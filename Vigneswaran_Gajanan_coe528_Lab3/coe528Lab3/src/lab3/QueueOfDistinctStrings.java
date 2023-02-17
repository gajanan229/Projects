/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3;

/**
 *
 * @author Gajanan Vigneswaran
 */
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
public class QueueOfDistinctStrings {
    // Overview: QueueOfDistinctStrings are mutable, bounded
    // collection of distinct strings that operate in
    // FIFO (First-In-First-Out) order.
    //
    // The abstraction function is:
    // a) Write the abstraction function here
    // AF(c) = an abstract queue d  (where c is a java QueueOfDistinctStrings object)
    //          where d.front = c.get(0)
    //                d.end = c.items.get(c.items.size() - 1)
    //                d.collection = c.items
    // The rep invariant is:
    // b) Write the rep invariant here
    // RI(c) = true if there are more than 1 instance of a string with the same characters
    //       = false otherwise 
    //
    //
    //the rep
    private ArrayList<String> items;
    // constructor
    public QueueOfDistinctStrings () {
        // EFFECTS: Creates a new QueueOfDistinctStrings object
        items = new ArrayList<String>();
    }
    // MODIFIES: this
    // EFFECTS: Appends the element at the end of the queue
    // if the element is not in the queue, otherwise
    // does nothing.
    public void enqueue(String element) throws Exception {
        if(element == null) {throw new Exception();}
        if(false == items.contains(element)){
        items.add(element);}
    }
    public String dequeue() throws Exception {
        // MODIFIES: this
        // EFFECTS: Removes an element from the front of the queue
        if (items.size() == 0){ throw new Exception();}
        return items.remove(0);
    }
    public boolean repOK() {
        // EFFECTS: Returns true if the rep invariant holds for this
        // object; otherwise returns false
        // c) Write the code for the repOK() here
        for (int i = 0; i < items.size(); i++){
            for (int k = i+1; k < items.size(); i++){
                if (items.get(i).equals(items.get(k))){
                    return true;
                }
            }
        }
        return false;
    }

    public String toString() {
        // EFFECTS: Returns a string that contains the strings in the
        // queue, the front element and the end element.
        // Implements the abstraction function.
        // d) Write the code for the toString() here
        return "front: " + items.get(0) + ", end: " + items.get(items.size() - 1) + ", collection: " + items.toString();
    }
    
    public static void main (String args[]){
        QueueOfDistinctStrings s = new QueueOfDistinctStrings();
        try {
            s.enqueue("en");
            s.enqueue("ww");
            s.enqueue("en");
        } catch (Exception ex) {
            Logger.getLogger(QueueOfDistinctStrings.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        System.out.println(s.toString());
    }
}
