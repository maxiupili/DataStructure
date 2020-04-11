/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let left=0;
    let right=s.length-1;
    while(s[left]===' '){
        left++;
    } 
    while(s[right]===' '){
        right--;
    }
     const dequeue=[]
     let word=''
    while(left<=right+1){
        if((left===right+1||s[left]===' ')&& word.length>0){
         
            dequeue.unshift(word)
            word=''
        }else if(s[left]!==' '){
            word+=s[left]
        }
        left++
    }
    
    return dequeue.join(' ')
};