#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct TreeNode {
   char command[MAX_SIZE];
   int times;
   struct TreeNode* left, * right;
}TreeNode;

TreeNode* root = NULL;

char reserved[10][MAX_SIZE] = {
   "break", "case", "do", "else", "for", "if", "int", "return", "switch", "while"
};

void inorder(TreeNode* root) {
   if (root){
      inorder(root->left);
      printf("%s : %d 회 \n", root->command, root->times);
      inorder(root->right);
   }
}

TreeNode* new_node(TreeNode* node) {
   TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
   strcpy(temp->command, node->command);
   temp->times = 1;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

TreeNode* used_node(TreeNode* node,char *command) {
   if (node == NULL)
      return new_node(node);

   if (strcmp(command, node->command) == 0) {
      node->times++;
   }
   else if (strcmp(command, node->command) > 0) {
      node->right = used_node(node->right, command);
   }
   else
      node->left = used_node(node->left, command);
   return node;
}

void file_inorder(TreeNode* root, FILE*fp2) {
   if (root)
   {
      file_inorder(root->left,fp2);
      fprintf(fp2, "%s : %d 회 \n", root->command, root->times);
      file_inorder(root->right,fp2);
   }
}

int main(void) {

   TreeNode* most_used = NULL;

   FILE* fp1 = fopen("bst_in.txt", "r");
   FILE* fp2 = fopen("bst_out.txt", "w");

   if (fp1 == NULL) {
      fprintf(stderr, "파일 열기 에러\n");
      exit(1);
   }

   if (fp2 == NULL) {
      fprintf(stderr, "파일 열기 에러\n");
      exit(1);
   }


   if (fp1 != NULL)
   {
      fseek(fp1, 0, SEEK_END);
      long filesize = ftell(fp1);
      fseek(fp1, 0, SEEK_SET);

      char* buffer = (char*)malloc(sizeof(char) * filesize);

      if (buffer != NULL) {
         fread(buffer, sizeof(char), filesize, fp1);

         for (int i = 0; i < 10; i++) {
            fseek(fp1, 0, SEEK_SET);
            while (!feof(fp1)) {
               if (strcmp(buffer, reserved[i]) == 0) {
                  root = used_node(root, reserved[i]);
               }
            }
            if (most_used == NULL || root->times < most_used->times)
               most_used = root;
         }
         free(buffer);
      }
      inorder(root);
      file_inorder(root, fp2);
      fprintf(fp2, "가장 많이 사용된 예약어: %s 횟수: %d \n", most_used->command, most_used->times);

      fclose(fp1);
      fclose(fp2);

      return 0;
   }
}
