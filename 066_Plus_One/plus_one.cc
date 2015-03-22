/**********************************************************************

 Given a non-negative number represented as an array of ans, plus one 
 to the number.

 The ans are stored such that the most significant digit is at the head 
 of the list.

**********************************************************************/

/*
 * Be careful when the significant digit should be changed
 */
vector<int> plusOne(vector<int> &digits) {
	bool carry = true;
	vector<int> ans = digits;

	for (int i = ans.size()-1; i >= 0 && carry; i--) {
		if (ans[i] < 9) {
			carry = false;
			++ans[i];
		} else {
			ans[i] = 0;
		}
	}
	if (carry)
		ans.insert(ans.begin(), 1);

	return ans;
}
