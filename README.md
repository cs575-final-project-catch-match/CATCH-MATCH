CS575: Final Project Report
Project Title: MATCH & CATCH
(STRING MATCHING PLAGIARISM DETECTOR)
Team Member(s): AHUJA HIMANSHU,GADI MOHIT,	LNU KARAN
 
 
 
I.	PROBLEM
String matching is a prevalent approach used in computer science. When applied to the problem of plagiarism detection, documents are compared for similar or same text overlaps. Numerous methods have been proposed to tackle this task, of which some have been adapted to external plagiarism detection. Checking a suspicious document in this setting requires the computation and storage of efficiently comparable representations for all documents in the reference collection to compare them pairwise. Generally, suffix document models, such as suffix trees or suffix vectors, have been used for this task. Nonetheless, substring matching remains computationally expensive, which makes it a non-viable solution for checking large collections of documents.
In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text.

II.	ALGORITHMS

A.	The longest common subsequence (LCS):
The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to all sequences in a set of sequences (often just two sequences). It differs from the longest common substring problem: unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences [1]. The longest common subsequence problem is a classic computer science problem, the basis of data comparison programs such as the diff utility, and has applications in computational linguistics and bioinformatics. It is also widely used by revision control systems such as Git for reconciling multiple changes made to a revision-controlled collection of files.
LCS[i,j]is the length of the LCS of X[1..m]with Y[1..n].
Case 1: what if X[i]≠Y[j]? Then, the desired subsequence has to ignore one of X[i] or Y[j] so we have: 
LCS[i,j] =max(LCS[i−1,j],LCS[i,j−1]).
Case 2: what if X[i] =Y[j]? Then the LCS of X[1..m] and Y[1..n] might as well match them up. 
LCS[i,j] = 1 +LCS[i−1,j−1].
To find the sequence, we just walk backwards through matrix starting the lower-right corner. If either the cell directly above or directly to the right contains a value equal to the value in the current cell, then move to that cell (if both to, then choose either one). If both such cells have values strictly less than the value in the current cell, then move diagonally up-left (this corresponds to applying Case 2) and output the associated character [3]. 

B.	Knuth–Morris–Pratt (KMP) algorithm:
	In computer science, the Knuth–Morris–Pratt string-searching algorithm searches for occurrences of a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.
Problem:  If a string(of size m) is given and a pattern(of size n) is given, then the problem is to find out whether the pattern is present in the string or not. And If the pattern is pattern is matching, then find out the position in the string.
Why KMP instead of naive?: KMP algorithm is an algorithm to overcome the high time complexity of naive string searching algorithm. The time complexity of the naive algorithm is O(mn) where m is the length of the string to be searched and n is the length of the pattern. In comparison, the KMP algorithm has a worst time complexity of O(m+n), where m is the length of the string to be searched and n is the length of the pattern[4].
The basic idea behind KMP’s algorithm is that whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window. We take advantage of this information to avoid matching the characters that we know will anyway match.
LPS: KMP algorithm preprocesses pattern and constructs an auxiliary LPS[] (or Pi table) of size m (same as size of pattern) which is used to skip characters while matching.
So after the Pi table is computed, our next step is to search the pattern in the given string.
Suppose the size of the string is 1 to n and size of pattern is 1 to m. Place i at string[1] and j at pattern[0] (pattern[0] is null initially). Check if string character at i matches with pattern character at j+1. Increment i and j if character at string[i] and pattern[j+1] matches. If j is equal to the length of the string, return the index (i-j). If the characters do not match, change the value of j to the corresponding value in the Pi table. Increment i if j = 0 and characters at i and j+1 do not match to start the search again from string[i+1]. Repeat the above procedure until the pattern is matched of end of string.

We can conclude that the worst case time complexity of KMP algorithm is O(m+n). For computing the Pi table, the time complexity is O(m) which is preprocessing. For searching, this algorithm has a time complexity of O(n)[5].
So in total the time complexity of KMP algorithm is O(m+n) which is better than the naive string search algorithm with time complexity of O(mn).

C.	Rabin Karp algorithm:
	In computer science, the Rabin–Karp algorithm is a string-searching algorithm that uses hashing to find any one of a set of pattern strings in a text. For text of length n and p patterns of combined length m, where n>m.
Hashing is done for simplicity of computation and is done by the following formula,
      Hash value for pattern p; p = (d * p + pat[i]) % q               
Hash value for text t;  t = (d * t + txt[i]) % q
Where i ranges from 0 to length of pattern p.
And ‘q’ is a prime number which is used to reduce Hash Collisions, greater the value of q better the efficiency[6].
A Hash Collision attack is an attempt to find two input strings of a hash function that produce the same hash result.
We remove collisions by comparing each element of the current text substring with pattern.
We use rehashing by sliding the m-length window one by one removing the least significant value; through;
hash(txt[s+1..s+m]) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h) + txt [s + m]) mod q
Here;
hash (txt[s .. s+m-1]) : Hash value at shift s.
hash (txt[s+1 .. s+m] ) : Hash value at next shift.

Since, the algorithm performs O(1) operations on each character of the text, and there are n characters in the text, this step takes O(n+m) time[7].
Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[].
Worst case time complexity:- O(nm)
The key to the Rabin–Karp algorithm's performance is the efficient computation of hash values of the successive substrings of the text.

III.	SOFTWARE DESIGN AND IMPLEMENTATION

A.	Software Design
The implementation consists of a main file, which checks the input.txt file with the files in the data set using the three algorithms. For each algorithm used a new file is created storing the details of the strings matched between input file and the data set file. The user has an option to increase or decrease the threshold value for the percentage of match between the files.
B.	Performance Evaluation: The preprocessing time and worst time complexity in the order of big Oh of the algorithms implemented by us are mentioned below in table 1:

REFERENCES

[1]	Hunt, J.W., Szymanski, T.G.: A Fast Algorithm for Computing Longest Common Subsequences. C. ACM ,(1977)
[2]	Kambayashi, Y., Nakatsu, N., Yajima, S.: Hierarchical String Pattern Matching Using Dynamic Pattern Matching Machines. Proc. IEEE COMPSAC 79,(1979)
[3]	L.Bergroth, H.Hakonen,T.Raita : A Survey of longest common subsequence algorithms. IEEE SPIRE 2000
[4]	Nimisha Singla, Deepak Garg: String Matching Algorithms and their Applicability in various Applications. IJSCE (2012)
[5]	D M Sunday, A very Fast Substring Search Algorithm, Communications of the ACM,August 1990.
[6]	 Chengguo Chang,Hui Wang, Comparison od Two Dimensional String Matching Algorithms,IEEE ICCSEE 2012
[7]	Predrag Brodanac, Leo Budin, Domagoj Jakobovic: Parallelized Rabin Karp method for exact String Matching. IEEE ITI 2011.
 


