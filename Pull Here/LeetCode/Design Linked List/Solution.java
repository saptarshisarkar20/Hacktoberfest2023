class listnode{
    int val;
    listnode next;
};

class MyLinkedList {
    listnode head;
    int size;
    public MyLinkedList() {
        head = null;
        size = -1;
    }
    
    public int get(int index) {
        int Data = 0;
    
        if(index < 0 || index > size)
        {
            Data = -1;
        }
        else
        {
            listnode temp = head;

            for(int i = 0; i <= size; i++)
            {
                if(i == index)
                {
                    Data = temp.val;
                    break;
                }
                temp = temp.next;
            }
        }
        return Data;
    }
    
    public void addAtHead(int val) {
        listnode newn = new listnode();
        newn.val = val;
        newn.next = null;

        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next = head;
            head = newn;
        }
        size++;
    }
    
    public void addAtTail(int val) {
        listnode newn = new listnode();
        newn.val = val;
        newn.next = null;

        if(head == null)
        {
            head = newn;
        }
        else
        {
            listnode temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = newn;
            newn.next = null;
        }
        size++;
    }
    
    public void addAtIndex(int index, int val) {
        if((index < 0) || (index > size+1))
        {
            return;
        }
        else if(index == 0)
        {
            addAtHead(val);
        }
        else if(index == size+1)
        {
            addAtTail(val);
        }
        else
        {
            listnode newn = new listnode();
            newn.val = val;
            newn.next = null;

            listnode temp = head;
            for(int i = 0; i < index -1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;
            size++;
        }
    }
    
    public void deleteAtIndex(int index) {
        if((index < 0) || (index > size))
        {
            return;
        }
        else if(index == 0)
        {
            head = head.next;
        }
        else if(index == size)
        {
            listnode temp = head;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        else
        {
            listnode temp = head;
            for(int i = 0; i < index - 1; i++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;
        }
        size--;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
