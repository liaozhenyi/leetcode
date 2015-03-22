/**********************************************************************

 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].
 
 Note:
 Could you optimize your algorithm to use only O(k) extra space?

**********************************************************************/

vector<int> getRow(int rowIndex) {
    vector<int> ans;
    
    for (int i = 0; i <= rowIndex; i++) {
        for (int j = ans.size()-1; j > 0; j--)
            ans[j] += ans[j-1];
        ans.push_back(1);
    }
    return ans;
}
