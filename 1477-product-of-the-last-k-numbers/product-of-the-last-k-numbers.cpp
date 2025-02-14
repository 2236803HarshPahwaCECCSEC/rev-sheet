class ProductOfNumbers {
public:
vector<int> keeptrack;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        keeptrack.push_back(num);
    }
    
    int getProduct(int k) {
        int res=1;
        if(k>keeptrack.size()) return 0;
        if(keeptrack.size()>=k){
            for(int i=keeptrack.size()-k;i<keeptrack.size();++i){
                res*=keeptrack[i];
            }
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */