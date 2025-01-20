/*Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.*/


struct Node{
    bool eow = false;
    Node* arr[26];

    bool checkIfExists(char c){
        return arr[c-'a'] != NULL;
    }

    void assignNew(char c, Node* newNode){
        arr[c-'a'] = newNode;
    }

    Node* nextNode(char c){
        return arr[c-'a'];
    }

    bool checkIfeow(){
        return eow;
    }

    void seteow(){
        eow = true;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto it: word){
            if(!curr->checkIfExists(it)) curr->assignNew(it, new Node());
            curr = curr->nextNode(it);
        }
        curr->seteow();
    }

    bool check(int i, string word, Node* curr){
        if(i == word.size()){
            if(curr -> checkIfeow()) return true;
            return false;
        }
        if(word[i] != '.'){
            if(!curr->checkIfExists(word[i])) return false;
            Node* newcurr = curr->nextNode(word[i]);
            return check(i+1, word, newcurr);
        } else {
            for(char c = 'a'; c <= 'z'; c++){
                if(curr->checkIfExists(c)){
                    Node* newcurr = curr->nextNode(c);
                    if(check(i+1, word, newcurr)) return true;
                }
            }
            return false;
        }
    }
    
    bool search(string word) {
        Node* curr = root;
        return check(0, word, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */