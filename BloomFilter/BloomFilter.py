import mmh3
 
class BloomFilter:
    
    def __init__(self, size, hashCount):
        self.size = size
        self.hashCount = hashCount
        self.bitArray = [0]*size

    def __len__(self):
        return self.size
    
    def hash(self, item, seed):
        return mmh3.hash(item, seed)    

    def add(self, item):
        for seed in range(self.hashCount):
            result = self.hash(item, seed) % self.size
            self.bitArray[result] = 1
            
    def lookup(self, item):
        for seed in range(self.hashCount):
            result = self.hash(item, seed) % self.size
            if self.bitArray[result] == 0:
                return False
        return True

    def __contains__(self, item):
        return self.lookup(item)   

