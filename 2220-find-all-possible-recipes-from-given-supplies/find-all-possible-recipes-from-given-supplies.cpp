class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    
      int  n = recipes.size();
      vector<string>result;
      unordered_set<string> st(begin(supplies),end(supplies));
      vector<bool> cooked(n,false);
      int cnt = n;


      while(cnt--){

      for(int i = 0;i<n;i++){
         if(cooked[i] == true){
                 continue;
            }
      bool banega = true;
        for(int j  = 0;j<ingredients[i].size();j++){
            if(st.find(ingredients[i][j]) == st.end()){
               banega = false;
               break;
            }
        }
         if(banega){
        result.push_back(recipes[i]);
        st.insert(recipes[i]);
        cooked[i] = true;
       }
      }
    }
     return result;
        
    }
};