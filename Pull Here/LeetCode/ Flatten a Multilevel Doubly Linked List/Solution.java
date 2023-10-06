/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node head1 = null;
    public Node tail = null;


    public void Rotate(Node ret)
    {
        if(ret == null)
        {
            return;
        }

        if(ret.next == null && ret.child == null)
        {
            InsertNode(ret.val);
            return;
        }
        else
        {
            if(ret.child != null)
            {
                InsertNode(ret.val);
                Rotate(ret.child);
                ret = ret.next;
                while(ret != null)
                {
                    InsertNode(ret.val);
                    ret = ret.next;
                }
            }
            else if(ret.next != null)
            {
                InsertNode(ret.val);
                Rotate(ret.next);
            }
            
        }
        
    }

    public void InsertNode(int Val)
    {
        Node newn = new Node();
        newn.val = Val;
        newn.next = null;
        newn.prev = null;

        if(head1 == null)
        {
            head1 = newn;
            tail = newn;
        }
        else
        {
           tail.next = newn;
           newn.prev = tail;
           tail = newn;
        }
    }

    public Node flatten(Node head) {
        Node temp = head;
        Rotate(head);
        return head1;   
    }
}