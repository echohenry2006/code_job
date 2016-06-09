#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cassert>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};


class Solution{
public:
    ListNode* sortList(ListNode* head);
    ListNode* bubble_sort(ListNode* head);
    ListNode* merge_sort(ListNode* head){
        if(head==NULL)
            return NULL;
        ListNode* p1=head;
        ListNode* p2;
        int len=0;
        while(p1!=NULL){
            len++;
            p1=p1->next;
        }

        if(len==1)
            return head;

        if(len==2){
            if(head->val>head->next->val){
                head->next->next=head;
                head=head->next;
                head->next->next=NULL;
            }
            //print(head);
            return head;
        }
        int i=0;
        p1=head;
        while((i++)<(len/2))p1=p1->next;
        p2=p1->next;
        p1->next=NULL;
        //print(head);
        //print(p2);
        p1=merge_sort(head);
        p2=merge_sort(p2);
        head=merge(p1,p2);
        return head;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1==NULL)return head2;
        if(head2==NULL) return head1;
        ListNode* p1=head1;
        ListNode* p2=head2;
        ListNode dummy(0);
        ListNode* p=&dummy;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                p->next=p1;
                p1=p1->next;
                p=p->next;
            }
            else{
                p->next=p2;
                p2=p2->next;
                p=p->next;
            }
        }
        p->next=(p1==NULL?p2:p1);
        return dummy.next;
    }

    void create(ListNode* &head, const vector<int> & vec){
        assert(head==NULL);
        ListNode dummy(0);
        ListNode* p=&dummy;
        for(int i=0;i<vec.size();i++){
            p->next=new ListNode(vec[i]);
            p=p->next;
        }
        p->next=NULL;
        head=dummy.next;
    }

    void destroy(ListNode* head){
        ListNode *p1=head;
        ListNode *p2;
        while(p1!=NULL){
            p2=p1;
            p1=p1->next;
            delete p2;
        }
    }

    void print(const ListNode* const head) const {
        const ListNode *p1=head;
        while(p1!=NULL){
            cout<<p1->val<<",";
            p1=p1->next;
        }
        cout<<endl;
    }
        



};


int main(int argc , char** argv)
{
    vector<int> v={3,6,2,1,5,4};
    ListNode* head=NULL;
    Solution sol;
    sol.create(head,v);
    sol.print(head);
    head=sol.merge_sort(head);
    sol.print(head);
    sol.destroy(head);
    return 0;


}



