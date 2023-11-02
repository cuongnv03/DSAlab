
class TrieNode:

    #Constructor, Time O(1), Space O(1)
    def __init__(self, c):
        self.data = c
        self.children = [] # list     
        self.isEnd = False

    #find the node by char, the same functionality as children[ch] in array implementation 
	#Time O(k), Space O(1), k is number of children of this node    
    def getChild(self, c):
        if self.children != None:
            for child in self.children:
                if child.data == c:
                    return child
        return None
       
class Trie:
    #Constructor, Time O(1), Space O(1)
    def __init__(self):
        self.root = TrieNode('')

    #Add a word to trie, Iteration, Time O(s), Space O(s), s is word length
    def insert(self, word) :            
        node = self.root
        for ch in word: 
            if node.getChild(ch) == None:
                node.children.append(TrieNode(ch))
            node = node.getChild(ch)            
        node.isEnd = True

    #find all word with given prefix
    #Time O(n), Space O(n), n is number of nodes involved (include prefix and branches)
    def autocomplete(self, prefix): 
        node = self.root
        res = []
        for char in prefix :
            node = node.getChild(char)
            if node == None: 
                return []
        self.helper(node, res, prefix[:-1])
        return res
      
    #recursive function called by autocomplete
    #Time O(n), Space O(n), n is number of nodes in branches
    def helper(self, node, res, prefix) :
        if node.isEnd:  
            res.append(prefix + node.data);  
        for child in node.children:
            self.helper(child, res, prefix + node.data)
      
t = Trie()      
t.insert("amazon") 
t.insert("amazon prime") 
t.insert("amazing") 			 
t.insert("amazing spider man")
t.insert("amazed")
t.insert("apple")

print(t.autocomplete('amaz'))
