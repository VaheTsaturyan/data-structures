#include <iostream>
#include "Set.h"

int main(){
	my::Set<int> st;
	st.insert(15);
	st.insert(10);
	st.insert(13);
	st.insert(7);
	st.insert(20);
	st.insert(17);
	st.insert(23);

	return 0;
}