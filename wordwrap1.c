#include<stdbool.h>       // checks whether a given word is present in the give dictionary.
#include<stdlib.h>        // for storing the words of the dictionary trie data structure is used.
#include<string.h>        // checking for the word in the dictionary is done recursive
#define ALPHA_SIZE 26

struct TrieNode{
    struct TrieNode* children[ALPHA_SIZE];
    bool endOfWord;
};
struct TrieNode* root = NULL;
struct TrieNode* createNode(){
    struct TrieNode* newnode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newnode->endOfWord = false;
    int i;
    for(i=0; i<ALPHA_SIZE; i++)
        newnode->children[i] = NULL;
    return newnode;
}
int convertToInt(char c){
    int index = (int)c - (int)('a');
    return index;
}

struct TrieNode* insert(struct TrieNode* root, char str[], int length){
    int i;
    struct TrieNode* temp = root;
    for(i=0; i<length; i++){
        int index = convertToInt(str[i]);
        if(temp->children[index]==NULL){
            temp->children[index]=createNode();
        }
        temp = temp->children[index];
    }
    temp->endOfWord=true;
    return root;
}
bool presentInTrie(struct TrieNode* root, char str[], int length){
    int i;
    struct TrieNode* temp = root;
    for(i=0; i<length; i++){
        int index = convertToInt(str[i]);
        if(temp->children[index]==NULL)
            return false;
        else{
            temp = temp->children[index];
        }
    }
    if(temp->endOfWord==true)
        return true;
    else
        return false;
}

bool isPresent(struct TrieNode* root, char str[], int start, int end){
    int length = end-start+1;
    char word[length];
    int i;
    for(i=0; i<length; i++){
        word[i] = str[start+i];
    }
    word[i] = '\0';
    if(presentInTrie(root, word, strlen(word)))
        return true;
    else
        return false;
}
bool wordPresent(struct TrieNode* root, char str[]){
 //   printf("word %s\n", str);
    int i;
    int length = strlen(str);
 //   printf("length = %d\n", length);
    if(length==0)
        return true;
    for(i=0; i<length; i++){
        
        if(isPresent(root, str, 0, i)){
            int newLength = length-(i+1);
            char newStr[newLength];
            int j;
            for(j=0; j<newLength; j++){
                newStr[j] = str[i+j+1];
            }
            newStr[j] = '\0';
            if(wordPresent(root, newStr))
                return true;
        }
    }  
    return false;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t>0){
        --t;
        struct TrieNode* root = NULL;
        root = createNode();
        int i, j, numberOfWords;
        scanf("%d", &numberOfWords);
        for(i=0; i<numberOfWords; i++){
            char str[15];
            scanf("%s", str);
            root = insert(root, str, strlen(str));
        }
        char targetWord[1000];
        scanf("%s", targetWord);
        int length = strlen(targetWord);
        if(length==0){
        printf("0\n");
        return;
        }
        if(wordPresent(root, targetWord))
            printf("1\n");
        else
            printf("0\n");
        
    }
}
