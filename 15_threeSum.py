def threeSum(nums):
    if(len(nums)<3):
        return []
    result_ls=[]
    bubbleSort(nums)
    hashmap={}
    for i in range(len(nums)):
        hashmap[str(nums)]=i 
    first=nums[0]
    for i in range(len(nums)-2):
        if(i!=0 and nums[i]==first):
            continue
        first=nums[i]
        if(first>0):
            return result_ls
        second=nums[i+1]
        for j in range(i+1,len(nums)-1):
            if(j!=i+1 and nums[j]==second):
                continue
            second=nums[j]
            third=-first-second
            if(third<0 or third<second):
                return result_ls
            index=hashmap.get(str(third))
            if(index!=None and index !=i and index!=j):
                result_ls.append([first,second,third])
    return result_ls

def bubbleSort(nums):
    for i in range(len(nums)):
        for j in range(len(nums)-i-1):
            if(nums[j]>nums[j+1]):
                tmp=nums[j]
                nums[j]=nums[j+1]
                nums[j+1]=tmp\

def testSort(nums):
    bubbleSort(nums)
    print(nums)

def testSum(nums):
    result_ls=threeSum(nums)
    print(result_ls)

if __name__=="__main__":
    nums=[-1,0,1,2,-1,-4]
    testSum(nums)