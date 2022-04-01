using System;

namespace zad1{

	public class Lista<T>{

      class element{
      	public T val;
      	public element next;
        public element prev;

        public element(T x){
        	this.val=x;
        	this.prev=null;
        	this.next=null;
        }
      }

      private element front;
      private element back;

      public Lista(){
      	this.front=null;
      	this.back=null;
      }

      public bool is_empty()
      {
      	if(this.front==null)
      	return true;
      	else return false;
      }

      public void push_front(T x)
      {
      	if(this.is_empty()==true)
      	{
      		this.front=new element(x);
      		this.back=this.front;
      	}
      	else{
         this.front.next=new element(x);
         this.front.next.prev=this.front;
         this.front=this.front.next;
     	}
      }

      public void push_back(T x)
      {
      	if(this.is_empty()==true)
      	{
      		this.back=new element(x);
      		this.front=this.back;
      	}
      	else{
         	this.back.prev=new element(x);
         	this.back.prev.next=this.back;
         	this.back=this.back.prev;
     	}

      }

      public T pop_front()
      {
      	if(this.is_empty()==true)
      	return default(T);
      	element temp=this.front;
      	this.front=temp.prev;
      	if(this.front!=null)
      	this.front.next=null;
      	return temp.val;
      }

      public T pop_back()
      {
      	if(this.is_empty()==true)
      	return default(T);
      	element temp=this.back;
      	this.back=temp.next;
      	if(this.back!=null)
      	this.back.prev=null;
      	return temp.val;
      }

	}
}
