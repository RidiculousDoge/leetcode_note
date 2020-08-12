# 快排：
def partition(low,high,arr):#分割取中
    if(low>high or low<0 or high <0):
        print("error!")
        return
    standard=arr[low]
    flag=True
    for i in range(low,high+1):
        if(arr[i]!=standard):
            flag=False
            break
    if(flag):
        return low
    while(high>low):
        while(arr[high]>=standard and high>low):# 这里检查high>low是非常重要的！！！
            high-=1
        arr[low]=arr[high]
        arr[high]=standard
        if(low==high):
            return high
        while(arr[low]<=standard and low<high):
            low+=1
        arr[high]=arr[low]
        arr[low]=standard
    return high
    


def quicksort(low,high,arr):
    if(low>=high):
        return
    mid=partition(low,high,arr)
    quicksort(low,mid,arr)
    quicksort(mid+1,high,arr)
# ----------------测试模块--------------------------------
def testPartition(arr):
    print(partition(0,len(arr)-1,arr))
def testQuicksort(arr):
    quicksort(0,len(arr)-1,arr)
    print(arr)
# ------------------------------------------------------------
if __name__=="__main__":
    arr=[0,1,2,-4,-4,-4,-4]
    testQuicksort(arr)