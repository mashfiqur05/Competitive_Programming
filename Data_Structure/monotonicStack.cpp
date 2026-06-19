/// Next Greater 
// nextGreater[i] = index of first greater element after i
vector<int> nextGreater(n + 1, -1);
stack<int> st;

for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) {
        st.pop();
    }

    if (!st.empty()) {
        nextGreater[i] = st.top();
    }

    st.push(i);
}

// Next Smaller Element
// nextSmaller[i] = index of first smaller element after i
vector<int> nextSmaller(n + 1, -1);
stack<int> st;

for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] >= a[i]) {
        st.pop();
    }

    if (!st.empty()) {
        nextSmaller[i] = st.top();
    }

    st.push(i);
}

// Previous Greater Element
// prevGreater[i] = index of first greater element before i

vector<int> prevGreater(n + 1, -1);
stack<int> st;

for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) {
        st.pop();
    }

    if (!st.empty()) {
        prevGreater[i] = st.top();
    }

    st.push(i);
}

// Previous Smaller Element
// prevSmaller[i] = index of first smaller element before i
vector<int> prevSmaller(n + 1, -1);
stack<int> st;

for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
        st.pop();
    }

    if (!st.empty()) {
        prevSmaller[i] = st.top();
    }

    st.push(i);
}