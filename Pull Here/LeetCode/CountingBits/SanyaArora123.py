from typing import List
class Solution:
    def countBits(self, n: int) -> List[int]:
        solList=[0]*(n+1)
        for i in range(0,n+1):
            solList[i]=i.bit_count()
        return solList    


