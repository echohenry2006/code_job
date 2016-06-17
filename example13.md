---
title: |
    [LeetCode] Maximum Product Subarray 求最大子数组乘积 - Grandyang -
    博客园
...

<div id="main">

<div id="mainContent">

<div class="forFlow">

<div id="post_detail">

<div id="topics">

<div class="post">

<span id="cb_post_title_url">[[LeetCode] Maximum Product Subarray 求最大子数组乘积](http://www.cnblogs.com/grandyang/p/4028713.html)</span> {.postTitle}
===========================================================================================================================================

<div class="clear">

</div>

<div class="postBody">

<div id="cnblogs_post_body">

 

Find the contiguous subarray within an array (containing at least one
number) which has the largest product.

For example, given the array `[2,3,-2,4]`,\
the contiguous subarray `[2,3]` has the largest product = `6`.

 

这个求最大子数组乘积问题是由最大子数组之和问题演变而来，但是却比求最大子数组之和要复杂，因为在求和的时候，遇到0，不会改变最大值，遇到负数，也只是会减小最大值而已。而在求最大子数组乘积的问题中，遇到0会使整个乘积为0，而遇到负数，则会使最大乘积变成最小乘积，正因为有负数和0的存在，使问题变得复杂了不少。。

 

比如，我们现在有一个数组[2, 3, -2,
4]，我们可以很容易的找出所有的连续子数组，[2], [3], [-2], [4], [2, 3],
[3, -2], [-2, 4], [2, 3, -2], [3, -2, 4], [2, 3, -2, 4],
然后可以很轻松的算出最大的子数组乘积为6，来自子数组[2, 3].

 

那么我们如何写代码来实现自动找出最大子数组乘积呢，我最先想到的方比较简单粗暴，就是找出所有的子数组，然后算出每一个子数组的乘积，然后比较找出最大的一个，需要两个for循环，第一个for遍历整个数组，第二个for遍历含有当前数字的子数组，就是按以下顺序找出子数组:
[2], [2, 3], [2, 3, -2], [2, 3, -2, 4],    [3], [3, -2], [3, -2, 4],  
 [-2], [-2, 4],    [4], 实现代码如下：

 

解法一：

<div class="cnblogs_code">

    class Solution {
    public:
       int maxProduct(int A[], int n) {
           if (n == 1) {
               return A[0];
           }
           else {
               int maxPro = A[0];
               int tmpPro = maxPro;
               for (int i = 0; i < n; ++i) {
                   tmpPro = A[i];
                   maxPro = max(maxPro, tmpPro);
                   for (int j = i + 1; j < n; ++j) {
                       tmpPro = tmpPro * A[j];
                       maxPro = max(maxPro, tmpPro);
                   }
               }
               return maxPro;
           }
       }
    }; 

</div>

 

我在本地测试的一些数组全部通过，于是兴高采烈的拿到OJ上测试，结果丧心病狂的OJ用一个有15000个数字的数组来测试，然后说我程序的运行时间超过了要求值，我一看我的代码，果然如此，时间复杂度O(n2),
得想办法只用一次循环搞定。我想来想去想不出好方法，于是到网上搜各位大神的解决方法，果然找到了一次循环搞定的算法，如下：

 

解法二：

<div class="cnblogs_code">

    class Solution {
    public:
        int maxProduct (int A[], int n) {
            if (n == 0) return 0;
            
            int maxIdx = 1, minIdx = 1;
            int out = A[0];
            for (int i = 0; i < n; ++i) {
                int oldMaxIdx = max (maxIdx, 1);
                if (A[i] > 0) {
                    maxIdx = oldMaxIdx * A[i];
                    minIdx *= A[i];
                } else {
                    maxIdx = minIdx * A[i];
                    minIdx = oldMaxIdx * A[i];
                }
                out = max (out, maxIdx);
            }
            return out;
        }
    };

</div>

 

仔细研读代码后，发现算法设计的很精妙。首先定义了两个变量maxIdx和minIdx，分别用于保存当前时刻的最大值和最小值，然后在遍历每一个数字的时候，更新当前的最大值和最小值，最终可以得到最大子数组乘积。

 

最开始时，设置当前当前最大值和最小值均为1，最终最大值为数组第一个数字，还要定义一个oldMaxIdx变量来保存之前最大值，然后最每一个遍历的数字根据其正负分别做不同的处理：

1.
当遍历到一个正数时，此时的最大值等于之前的最大值乘以这个正数，此时的最小值等于它本身再乘以这个正数。

2.
当遍历到一个负数时，此时的最大值等于之前最小值乘以这个负数，这时候问题就来了，挖掘技术哪家强？哈哈，言归正传，这时候问题就来了，当之前的最小值是负数时，负负得正没有问题，当之前的最小值是正数时，在乘以一个负数，当前最大值就变成负数了，这怎么办，没关系，在下次循环时，会和1比较取大的，负数就被舍弃了，程序继续正常执行。此时的最小值等于之前最大值（肯定是正数）乘以这个负数，还是负数。

3\. 在每遍历完一个数时，都要更新最终的最大值。

 

P.S.
如果这里改成去最小值的话，就是求最小子数组乘积，并且时间复杂度是醉人的O(n)，是不是很强大呢。。。再次拿到OJ上测试，完美通过，膜拜大神ing。。。

 

以下摘自OJ官方解答，大体思路相同，写法更加简洁：

Besides keeping track of the largest product, we also need to keep track
of the smallest product. Why? The smallest product, which is the largest
in the negative sense could become the maximum when being multiplied by
a negative number.

Let us denote that:

<div class="cnblogs_code">

    f(k) = Largest product subarray, from index 0 up to k.

</div>

 

Similarly,

<div class="cnblogs_code">

    g(k) = Smallest product subarray, from index 0 up to k.

</div>

 

Then,

<div class="cnblogs_code">

    f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
    g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )

</div>

 

There we have a dynamic programming formula. Using two arrays of
size *n*, we could deduce the final answer as f(*n*-1). Since we only
need to access its previous elements at each step, two variables are
sufficient.

<div class="cnblogs_code">

    public int maxProduct(int[] A) {
       assert A.length > 0;
       int max = A[0], min = A[0], maxAns = A[0];
       for (int i = 1; i < A.length; i++) {
          int mx = max, mn = min;
          max = Math.max(Math.max(A[i], mx * A[i]), mn * A[i]);
          min = Math.min(Math.min(A[i], mx * A[i]), mn * A[i]);
          maxAns = Math.max(max, maxAns);
       }
       return maxAns;
    }

</div>

 

根据上述描述可以写出代码如下：

 

解法三：

<div class="cnblogs_code">

    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.empty()) return 0;
            int res = nums[0], mn = nums[0], mx = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                int tmax = mx, tmin = mn;
                mx = max(max(nums[i], tmax * nums[i]), tmin * nums[i]);
                mn = min(min(nums[i], tmax * nums[i]), tmin * nums[i]);
                res = max(res, mx);
            }
            return res;
        }
    };

</div>

 

<span id="cb_post_title_url">[LeetCode All in One
题目讲解汇总(持续更新中...)](http://www.cnblogs.com/grandyang/p/4606334.html)</span>

</div>

<div id="MySignature">

</div>

<div class="clear">

</div>

<div id="blog_post_info_block">

<div id="BlogPostCategory">

</div>

<div id="EntryTag">

</div>

<div id="blog_post_info">

</div>

<div class="clear">

</div>

<div id="post_next_prev">

</div>

</div>

</div>

<div class="postDesc">

posted @ <span id="post-date">2014-10-16 14:24</span>
[Grandyang](http://www.cnblogs.com/grandyang/) 阅读(<span
id="post_view_count">...</span>) 评论(<span
id="post_comment_count">...</span>)
[编辑](http://i.cnblogs.com/EditPosts.aspx?postid=4028713) [收藏](#)

</div>

</div>

</div>

</div>

<div id="blog-comments-placeholder">

</div>

<div id="comment_form" class="commentform">

<div id="divCommentShow">

</div>

<div id="comment_nav">

<span id="span_refresh_tips"></span><span
id="lnk_RefreshComments">[刷新评论](javascript:void(0);)</span>[刷新页面](#)[返回顶部](#top)

</div>

<div id="comment_form_container">

</div>

<div id="ad_text_under_commentbox" class="ad_text_commentbox">

</div>

<div id="ad_t2">

</div>

<div id="opt_under_post">

</div>

<div id="ad_c1" class="c_ad_block">

</div>

<div id="under_post_news">

</div>

<div id="ad_c2" class="c_ad_block">

</div>

<div id="under_post_kb">

</div>

<div id="HistoryToday" class="c_ad_block">

</div>

</div>

</div>

</div>

<div id="sideBar">

<div id="sideBarMain">

<div class="newsItem">

### 公告 {.catListTitle}

<div id="blog-news">

</div>

</div>

<div id="blog-calendar" style="display:none">

</div>

<div id="leftcontentcontainer">

<div id="blog-sidecolumn">

</div>

</div>

</div>

</div>

<div class="clear">

</div>

</div>

<div class="clear">

</div>

<div id="footer">

Copyright ©2016 Grandyang

</div>
