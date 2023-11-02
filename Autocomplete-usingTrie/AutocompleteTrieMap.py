
class TrieNode:

    #constructor, Time O(1) Space O(1)
    def __init__(self, c):
        self.data = c
        self.isEnd = False
        self.children = {} #map

class Trie:
    #constructor, Time O(1) Space O(1)
    def __init__(self):
        self.root = TrieNode('')
    
    #Add a word to trie, Time O(s) Space O(1) s is word length
    def insert(self, word):
        node = self.root
        for ch in word:
            if not ch in node.children:
                node.children[ch] = TrieNode(ch)   
            node = node.children[ch]                  
        node.isEnd = True
   
    #find all word with given prefix
	#Time O(n), Space O(n), n is number of nodes involved (include prefix and branches)
    def autocomplete(self, word):
        res = []
        node = self.root
        for ch in word:           
            if ch in node.children:
                node = node.children[ch]
            else:
                return []
        self.helper(node, res, word[:-1]) #except the last "ama", node is "z"
        return res

    #recursive function called by autocomplete
	#Time O(n), Space O(n), n is number of nodes in branches
    def helper(self, node, res, prefix):
        if node.isEnd:
            res.append(prefix + node.data)       
        for child in node.children.values():
            self.helper(child, res, prefix + node.data)

t = Trie()         
t.insert("amazon") 
t.insert("amazon prime") 
t.insert("amazing") 			 
t.insert("amazing spider man")
t.insert("amazed")
t.insert("apple")

a = t.autocomplete("amaz")
print(a)