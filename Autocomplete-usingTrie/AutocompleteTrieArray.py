
class TrieNode:    

    #Constructor, Time O(1), Space O(1), 128 is constant
    def __init__(self, c):
        self.children = [None]*128 #don't use 26 if there is space or other special characters
        self.isEnd = False
        self.data = c
		   		
class Trie:

    #Constructor, Time O(1), Space O(1)
    def __init__(self):
        self.root = TrieNode('')

    #inserts a word into the trie, Iteration
	#Time O(s), Space O(s), s is word length
    def insert(self, word):
        node = self.root
        for ch in word:
            idx = ord(ch)
            if not node.children[idx]:
                node.children[idx] =  TrieNode(ch)
            node = node.children[idx]
        node.isEnd = True

    #returns all words with given prefix
    #Time O(n), Space O(n), n is number of nodes included(prefix and branches) 
    def autocomplete(self, prefix):
        node = self.root
        res = []
        for ch in prefix:
            node = node.children[ord(ch)]
            if node == None:
                return []     
        self.helper(node, res, prefix[:-1]) 
        return res   

	#recursion function called by autocomplete, Time O(n), Space O(n)	
    # n is number of nodes in bra
    def helper(self, node, res, prefix):
        if node == None:
            return
        if node.isEnd :
            res.append(prefix + node.data)		   	      	   
        for child in node.children:	         
            self.helper(child, res,prefix + node.data)		             

t = Trie()      
t.insert("amazon") 
t.insert("amazon prime") 
t.insert("amazing") 			 
t.insert("amazing spider man")
t.insert("amazed")
t.insert("apple")

print(t.autocomplete('amaz'))