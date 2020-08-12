def lengthOfLongestSubstring(s):
        """
        :type s: str
        :rtype: int
        """
        if(len(s)==0):
            return 0
        if(len(s)==1):
            return 1
        
        # 给定一个start,end往后走，边走边把元素放进hashset中；停下来的时候记录长度,然后start++
        max_len=1
        for start in range(len(s)):
            hashset=set([])
            end=start
            while(end<len(s) and s[end] not in hashset ):
                hashset.add(s[end])
                end+=1
            if(end==len(s)):
                return end-start
            if(end-start>max_len):
                max_len=end-start
        return max_len

s='abcabcbb'
print(lengthOfLongestSubstring(s))