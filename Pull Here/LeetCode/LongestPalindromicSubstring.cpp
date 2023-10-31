   bool isPalindrome(string &s,int i,int j){
        //have to be done with dp
        //  if(s.size()==0 || s.size()==1){
        //     return true;
        // }
        // int i=0;
        // int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size()==0 || s.size()==1){
            return s;
        }
        int maxlength=INT_MIN;
        string maxstr="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                //string temp=s.substr(i,j-i+1);
                 // int lengthoftemp=temp.size();
                bool ans=isPalindrome(s,i,j);
                int length=j-i+1;
                if(ans && length>maxlength){
                    
                        maxlength=length;
                        maxstr=s.substr(i,j-i+1);
                    
                }

            }
        }
        return maxstr;
    }
