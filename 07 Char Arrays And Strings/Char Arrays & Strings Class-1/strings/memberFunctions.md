

```cpp
string name = "Maharana Pratap";
```

👉 Ek string banayi `"Maharana Pratap"`.

---

```cpp
cout<<name[0]<<endl;  //M
```

👉 Indexing ka use karke **0th character** print hoga → `M`.

---

```cpp
cout<<name.at(9)<<endl; //P
```

👉 `.at()` bhi indexing jaisa hi hota hai, bas agar galat index diya to **runtime error throw karega**.
Index `9` pe `"P"` hai.

---

```cpp
cout<<name.front()<<endl; //M
cout<<name.back()<<endl; //p
```

👉 `.front()` → first char → `M`
👉 `.back()` → last char → `p`

---

```cpp
cout<<name.length()<<endl; //15
```

👉 String ki length (characters count including spaces) = `15`.

---

```cpp
auto it = name.begin(); 
while(it!=name.end()){
    cout<<*it<<" ";
    it++;
}
```

👉 Ye ek **iterator** hai jo string ke har character pe move karta hai.
Output:

```
M a h a r a n a   P r a t a p
```

---

```cpp
cout<<name.substr(3,5)<<endl;  //ara
```

👉 `.substr(start, length)`
Index 3 se 5 characters → `"arana"` (lekin tumhare comment me `ara` likha hai, actually `"arana"` milega).

```cpp
cout<<name.substr(7)<<endl;   //a Pratap
```

👉 Index 7 se leke end tak → `"a Pratap"`

---

```cpp
string word="Pra";
int findd = name.find(word); //return index at which string is found
cout<<findd<<endl;
```

👉 `"Pra"` first time index `9` pe start hota hai → output = `9`.

```cpp
if(name.find(word)!= string::npos){
    // found
} else {
    // not found
}
```

👉 Agar substring nahi milta to `.find()` `string::npos` return karta hai (basically `-1` ka equivalent).
Yahaan `"Pra"` mila hai, to condition true hogi.

---

```cpp
name.clear();
if(name.empty()){
    cout<<"string is empty"<<endl;
}
```

👉 `.clear()` → pura string delete kar deta hai.
👉 `.empty()` check karta hai ki khaali hai ya nahi. Yaha output:

```
string is empty
```

---

```cpp
string fName = "Saumya";
string lName = "Yadav";
string ans = fName+" "+lName;
cout<<ans<<endl;
```

👉 Strings ko `+` se concatenate kiya ja sakta hai. Output:

```
Saumya Yadav
```

---

```cpp
cout<<fName.compare(lName)<<endl;
```

👉 `.compare()` function **lexicographical comparison** karta hai:

* 0 → agar dono equal hain
* negative → agar `fName < lName`
* positive → agar `fName > lName`

Example: `"Saumya"` vs `"Yadav"` → `"S"` (ASCII 83) vs `"Y"` (ASCII 89).
Since `83 < 89`, output hoga **negative number** (usually `-1`).

---

### ✅ Output (step-wise)

```
M
P
M
p
15
M a h a r a n a   P r a t a p 
arana
a Pratap
9
string is empty
Saumya Yadav
-1
```

---

👉 Bhai, kya tu chaahta hai mai string ke **aur important functions** (like `erase`, `insert`, `replace`, `stoi`, `to_string`) bhi examples ke saath explain karun?
