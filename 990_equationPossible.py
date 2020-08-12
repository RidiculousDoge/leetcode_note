def getOtherVarValue(left_var_value,sig):
    if(sig=='!'):
        sig_value=1
    if(sig=='='):
        sig_value=0
    right_var_value=left_var_value ^ sig_value
    return right_var_value
    
def writeIntoHashmap(hashmap,left_var,right_var,sig):
    if(not hashmap.get(left_var)==None):    # 若已有left_var
        left_var_value=hashmap.get(left_var)
    else:
        left_var_value=0
        hashmap[left_var]=0
    right_var_value=getOtherVarValue(left_var_value,sig)
    if(checkPoss(hashmap,right_var,right_var_value)):
        hashmap[right_var]=right_var_value
        hashmap['flag']=0
    else:
        # flag=1代表等式不成立
        hashmap['flag']=1
        

#在hashmap中检查等式是否成立
def checkPoss(hashmap,right_var,right_var_value):
    return (hashmap.get(right_var)==right_var_value or hashmap.get(right_var)==None)
            
        
def equationsPossible(equations):
    hashmap={}
    for equation in equations:
        left_var=equation[0]
        sig=equation[1]
        right_var=equation[3]
        writeIntoHashmap(hashmap,left_var,right_var,sig)
    return (not bool(hashmap.get('flag')))

def main():
    equations=['a==b','b==a']
    print(equationsPossible(equations))

main()