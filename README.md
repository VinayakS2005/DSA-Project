# DSA-Project
DSA project on minimizing cash flow
STRATEGY

 1. Compute Net Balance
   For every transaction [A, B, X]:
    balance[B] += X   (B receives)
    balance[A] -= X   (A pays)
    People with balance = 0 need no further action.
 
  2. Split & Sort
    debtors   — people with balance < 0, sorted by |balance| descending
    creditors — people with balance > 0, sorted by balance descending
 
   3. Greedy Two-Pointer Matching
   While both lists are non-empty:
   amount = min(|debtors.top()|, creditors.top())
    emit transaction: debtor pays creditor 'amount'
    reduce both balances by 'amount'
    pop whoever reached 0
Time complexity: O(N log N) for sorting + O(N) for the two-pointer pass




    
    
