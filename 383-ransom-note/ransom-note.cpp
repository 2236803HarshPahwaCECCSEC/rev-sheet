class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

      map<int,int> check;
      for(auto el:magazine){
        check[el-'a']++;
      }
      for(auto el:ransomNote){
        if(check[el-'a']<=0){return false;}
        check[el-'a']--;
      }  
      return true;
    }
};