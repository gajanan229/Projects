/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe528lab1;

/**
 *
 * @author Gajanan Vigneswaran
 */
abstract class Passenger {
    String name;
    int age;
    public Passenger(String name, int age){
        this.name = name;
        this.age = age;
    }
    
     public void setName (String name){
        this.name = name;
    }
    public String getName (){
        return name;
    }
    
    public void setAge (int age){
        this.age = age;
    }
    public int getAge (){
        return age;
    }
    
    public abstract double applyDiscount(double p);
}

class Member extends Passenger{
    
    int yearsOfMembership;
    public Member(String name, int age, int yearsOfMembership){
        super(name, age);
        this.yearsOfMembership = yearsOfMembership;
    }
    
    public double applyDiscount(double p){
        if (yearsOfMembership > 5){
            return (p*0.5);
        }
        else if (yearsOfMembership > 1 && yearsOfMembership <= 5){
            return (p*0.9);
        }
        else{
            return p;
        }
    }
}
class NonMember extends Passenger{
    
    public NonMember(String name, int age){
        super(name, age);
    }
    
    public double applyDiscount(double p){
        if (age > 65){
            return (p*0.9);
        }
        else{
            return p;
        }
    }
}