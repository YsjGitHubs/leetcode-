/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *psRst;
    if((psRst = (struct ListNode *)calloc(1,sizeof(struct ListNode))) == NULL)
        return NULL;
    unsigned int num1=0;
    unsigned int num2=0;
    unsigned int Rst=0;
    struct ListNode* pstemp;
    int i=0;
    //将两个数据提取出来
    if(l1->val==0){
        num1=0;
    }
    else{
        pstemp = l1;
        while(pstemp!=NULL){
            num1+=pstemp->val * 10 * i;
            i++;
            pstemp=pstemp->next;
        }
    }  
    i = 0;
    if(l2->val==0){
        num2=0;
    }
    else{
        pstemp = l2;
        while(pstemp!=NULL){
            num2+=pstemp->val * 10 * i;
            i++;
            pstemp=pstemp->next;
        }
    }  
   
    //完成加法运算
    Rst = num1+num2;
    //将结果存入链表
    i=1;
    unsigned int temp;
    pstemp=psRst;
    if(Rst==0){
        psRst->val = 0;
    }
    while(Rst != 0){
        temp = Rst%(10*i);
        pstemp->val=temp;
        pstemp->next=(struct ListNode *)calloc(1,sizeof(struct ListNode));
        pstemp=pstemp->next;
        Rst-=temp*(i-1);
    }

    return psRst;
}