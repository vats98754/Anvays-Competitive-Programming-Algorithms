#include <iostream>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

// for indexed_set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    bitset<10> b(string("0010011010"));// default value is 0, size is 10 (index increases from right to left)
    // s[1] = 1;
    // s[3] = 1;
    // s[4] = 1;
    // s[7] = 1;
    cout << b.count() << "\n"; // displays the number of 1s in the bitset (4)

    // examples of bit operations with logic gates using single signs instead of double signs (e.g. & instead of &&)
    // put brackets around each. & means AND, | means OR, and ^ means XOR
    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a&b) << "\n"; // 0010010000
    cout << (a|b) << "\n"; // 1011111110
    cout << (a^b) << "\n"; // 1001101110

    deque<int> d; // DEQUE is slower than vector but has pop_front() and push_front() features
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]

    stack<int> s; // stack can only allow the top element to be accessed, LIFO [.push(), .pop(), .top()]
    s.push(3);
    s.push(2);
    s.push(5);
    cout << s.top() << " "; // 5
    s.pop(); // removes the top element
    cout << s.top() << "\n"; // 2
    
    queue<int> q; // queue can only access the first and last elements, FIFO [.push(), .pop(), .front()]
    q.push(3);
    q.push(2);
    q.push(5);
    cout << q.front() << " "; // 3
    q.pop(); // removes the frontmost element
    cout << q.back() << "\n"; // 5

    priority_queue<int> pq; // by default sorted in descending order where the top elements is the maximum, faster retrieval than set and same methods as queue
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);
    cout << pq.top() << "\n"; // 7
    pq.pop();
    cout << pq.top() << "\n"; // 5
    pq.pop();
    pq.push(6);
    cout << pq.top() << "\n"; // 6
    pq.pop();

    // priority_queue<int, vector<int>, greater<int>> pq; is used to reverse the order so the min is on top
    
    // the following is a policy-based DS, the indexed set. This is good because it acts as a SORTED ARRAY in ascending order
    
    indexed_set t;
    t.insert(2);
    t.insert(3);
    t.insert(7);
    t.insert(9);
    auto x = t.find_by_order(2); // t.find_by_order(p) finds the element at position p
    cout << *x << "\n"; // 7

    // t.order_of_key(x) finds the position x is in, and if x doesn't exist in the set, then it returns the position it WOULD HAVE occupied
    cout << t.order_of_key(7) << "\n"; // 2
    cout << t.order_of_key(6) << "\n"; // 2
    cout << t.order_of_key(8) << "\n"; // 3

    return 0;
}