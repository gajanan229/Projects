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
public class Flight {
    private int flightNumber;
    private String origin; 
    private String destination;
    private String departureTime;
    private int capacity;
    private int numberOfSeatsLeft; 
    private double originalPrice;
    public Flight(int flightNumber, String origin, String destination, String departureTime, int capacity, double originalPrice){
        if(origin.equals(destination)){
            throw new IllegalArgumentException("the origin of the flight cannot be the same as the destination");
        }
        this.flightNumber = flightNumber;
        this.origin = origin;
        this.destination = destination;
        this.departureTime = departureTime;
        this.capacity = capacity;
        this.originalPrice = originalPrice;
        numberOfSeatsLeft = capacity; 
    }
    
    public void setFlightNumber (int flightNumber){
        this.flightNumber = flightNumber;
    }
    public int getFlightNumber (){
        return flightNumber;
    }
    
    public void setOrigin (String origin){
        this.origin = origin;
    }
    public String getorigin (){
        return origin;
    }
    
    public void setDestination (String destination){
        this.destination = destination;
    }
    public String getDestination (){
        return destination;
    }
    
    public void setDepartureTime (String departureTime){
        this.departureTime = departureTime;
    }
    public String getDepartureTime (){
        return departureTime;
    }
    
    public void setCapacity (int capacity){
        this.capacity = capacity;
    }
    public int getCapacity (){
        return capacity;
    }
    
    public void setOriginalPrice (double originalPrice){
        this.originalPrice = originalPrice;
    }
    public double getOriginalPrice (){
        return originalPrice;
    }
    
    public void setNumberOfSeatsLeft (int numberOfSeatsLeft){
        this.numberOfSeatsLeft = numberOfSeatsLeft;
    }
    public int getNumberOfSeatsLeft (){
        return numberOfSeatsLeft;
    }
    
    public boolean bookASeat(){
        if (numberOfSeatsLeft>0){
            numberOfSeatsLeft--;
            return true;
        }
        else{
            return false;
        }
    }
    @Override
    public String toString(){
        return("Flight " + flightNumber + ", " + origin + " to " + destination + ", " + departureTime + ", original price: " + originalPrice +"$");
    }
    
}
