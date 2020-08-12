def addBinary(a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        '''
        应该先把短的补0，最后把补的0去掉
        '''
        
        i=len(a)-1
        j=len(b)-1
        cin=0
        result_ls=[]
        while(i>=0 and j>=0):
            a_cur=int(a[i])
            b_cur=int(b[j])
            cout_cur=b_cur*(a_cur^cin)+a_cur*cin
            result_cur=b_cur^(a_cur^cin)
            result_ls.append(str(int(result_cur)))
            i-=1
            j-=1
            cin=cout_cur
        if(cin==0):
            if(len(a)>len(b)):
                result_ls.append(a[0:i-j-1])
            elif (len(a)<len(b)):
                result_ls.append(b[0:j-i-1])
        else:

        
        result_str=''
        for i in range(len(result_ls)):
            result_str+=result_ls[i]
        return result_str

def main():
    a='11'
    b='1'
    result=addBinary(a,b)
    print(result)

main()