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
public class Ticket {
    private Passenger passenger;
    private Flight flight;  
    private double price;
    private int ticketNumber;
    private static int number;
    

    public Ticket (Passenger p, Flight flight, double price){
       passenger = p;
       this.flight = flight;
       this.price = price;
       ticketNumber = number;
       number++;
    }
    public void setPassenger (Passenger passenger){
        this.passenger = passenger;
    }
    public Passenger getPassenger (){
        return passenger;
    }
    
    public void setFlight (Flight flight){
        this.flight = flight;
    }
    public Flight geFlight(){
        return flight;
    }
    
    public void setPrice (double price){
        this.price = price;
    }
    public double getPrice (){
        return price;
    }
    
     public void setTicketNumber (int ticketNumber){
        this.ticketNumber = ticketNumber;
    }
    public int getTicketNumber (){
        return ticketNumber;
    }
    
    @Override
    public String toString(){
        return(passenger.getName() + ", Flight" + flight.getFlightNumber() + ", " + flight.getorigin() + " to " + flight.getDestination() + 
              ", " + flight.getDepartureTime() + ", original price:" + flight.getOriginalPrice() +"$, ticket price: $" + price);
    }
}
