class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false;
        for(int i=0;i<arr.size()-2;i++) {
            if(arr[i] & 1 && arr[i+1] & 1 && arr[i+2] & 1) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        while (i + 2 < arr.size()) {
            if ((arr[i] & 1) && (arr[i+1] & 1) && (arr[i+2] & 1))
                return true;
            if (!(arr[i+2] & 1)) i += 3;
            else if (!(arr[i+1] & 1)) i += 2;
            else i++;
        }
        return false;
    }
};


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (int i = 0 ; i < arr.size() ; i++) {
            if (arr[i] & 1) ++odds;
            else odds = 0;
            if (odds == 3) return true;
        }
        return false;
    }
};