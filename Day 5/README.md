<h3> Add and Search Word - Data structure design </h3>
<div><p>Design a data structure that supports the following two operations:</p>

<pre>void addWord(word)
bool search(word)
</pre>

<p>search(word) can search a literal word or a regular expression string containing only letters <code>a-z</code> or <code>.</code>. A <code>.</code> means it can represent any one letter.</p>

<p><strong>Example:</strong></p>

<pre>addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -&gt; false
search("bad") -&gt; true
search(".ad") -&gt; true
search("b..") -&gt; true
</pre>

<p><b>Note:</b><br>
You may assume that all words are consist of lowercase letters <code>a-z</code>.</p>
</div>
<div class="css-haw22i"><div class="expandable-panel__YLuE" style="background-color: white; margin-top: 0px;"><div class="center__3_51"><div class="expand-btn__2cag"><span class="text">&nbsp;</span><i class="fa fa-lightbulb-o" aria-hidden="true"></i><span class="text">&nbsp;&nbsp;</span>Show Hint #1&nbsp;&nbsp;<i class="fa fa-caret-down" aria-hidden="true"></i></div></div><div class="expandable-wrapper__37QK"><div><div class="line__2vww"></div><div class="content__1q_0"><div>You should be familiar with how a Trie works. If not, please work on this problem: <a href="https://leetcode.com/problems/implement-trie-prefix-tree/">Implement Trie (Prefix Tree)</a> first.</div></div></div></div></div></div>