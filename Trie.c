#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define alpha_size 26
struct TrieNode{
    struct TrieNode* children[alpha_size];
    bool endOfString;
};

struct TrieNode* createNode(){
    
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->endOfString=false;
    int i;
    for(i=0; i<alpha_size; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}
int convertCharToIndex(char c){
    int index = (int)c - (int)('a');
    return index;
}
char convertIndexToChar(int index){
    return (char)(index + 'a');
}

struct TrieNode* insert(struct TrieNode* root, char str[]){
    struct TrieNode* current = root;
    int level;
    for(level=0; level<strlen(str); level++){
        int index = convertCharToIndex(str[level]);
        if(current->children[index]==NULL){
            current->children[index] = createNode();
            
        }
        current=current->children[index];
    }
    current->endOfString=true;
}

bool search(struct TrieNode* root, char str[]){
    struct TrieNode* current = root;
    int length=strlen(str);
    int level;
    for(level=0; level<length; level++){
    //    printf("\n%d", level);
        int index=convertCharToIndex(str[level]);
        if(current->children[index]!=NULL){
            current=current->children[index];
        }
        else
            return false;
    }
    if(current->endOfString==true)
        return true;
    else
        return false;
    
}
bool isLeafNode(struct TrieNode* root) 
{ 
  //  return root->endOfString != false; 
    if(root->endOfString==true)
        return true;
    return false;
} 
void printTrie(struct TrieNode* head, char str[], int level){
    if(isLeafNode(head)){
        str[level]='\0';
        printf("%s\n", str);
    }
    int i;
    for(i=0; i<alpha_size; i++){
        if(head->children[i]!=NULL){
            str[level] = i+'a';
            printTrie(head->children[i], str, level+1);
        }
    }
} 

int main(){
  //char strings[][6] = {"answer", "the",  "there", 
  //                     "any", "by", "bye", "their" }; 
  

 //   char strings[100][1];
 //   strings[0] = "fouluukbhrw";
    int i;
 //   char strings[][10] = {"jfdyrjd",  "ikbxjtf", "svkypnk", "srvawvv" ,"krfwyiu" ,"puzxecv"};
    
    int numberOfStrings;
	    scanf("%d", &numberOfStrings);
	    char strings[numberOfStrings][100];
	
	    
	    for(i=0; i<numberOfStrings; i++){
	        scanf("%s", strings[i]);
	    }
	//    char query[100];
	//    scanf("%s", query);  

    struct TrieNode* root = createNode();
  //  int i;
    int len = sizeof(strings)/sizeof(strings[0]);
 //   int len = numberOfStrings;
    printf("len = %d", len);
    for(i=0; i<len; i++){
        printf("%s  ", strings[i]);
        insert(root, strings[i]);
    }
    
 //   printTrie(root, str, 0);
    int level=0;
    char str[20];
    printTrie(root, str, level);
    char query[] = "answer";
    if(search(root, query))
        printf("\nfound");
    else 
        printf("\nnot found");  

}