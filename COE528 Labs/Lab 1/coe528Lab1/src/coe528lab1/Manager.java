/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe528lab1;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author Gajanan Vigneswaran
 */
public class Manager {
  
    ArrayList<Flight> flights = new ArrayList<>(); 
    Scanner sc = new Scanner(System.in);
    
    public void createFlights(){
        
        System.out.println("Enter flight number: ");
        int flightNumber = sc.nextInt();
        sc.nextLine();
        
        System.out.println("Enter origin of flight: ");
        String origin = sc.nextLine();
        
        System.out.println("Enter flight destination: ");
        String destination = sc.nextLine();
        
        System.out.println("Enter flight departure time (dd/mm/yy 0:00 pm): ");
        String departureTime = sc.nextLine();
        
        System.out.println("Enter flight capacity: ");
        int capacity = sc.nextInt();
        
        System.out.println("Enter flight original price: ");
        double originalPrice = sc.nextDouble();
        
        flights.add(new Flight(flightNumber, origin, destination, departureTime, capacity, originalPrice));
    }
    
    public void displayAvailableFlights(String origin, String destination){
        for (Flight F: flights){
            if (F.getorigin().equals(origin) && F.getDestination().equals(destination) && F.getNumberOfSeatsLeft() > 0){
                System.out.println(F);
            }
        }
    }
    
    public Flight getFlight(int flightNumber){
        for (Flight F: flights){
            if (F.getFlightNumber() == flightNumber){
                return F;
            }
        }
        return null;
    }
    
    public void bookSeat(int flightNumber, Passenger p){
        for (Flight F: flights){
            if (F.getFlightNumber() == flightNumber && F.bookASeat()){
                Ticket ticket = new Ticket(p, F, p.applyDiscount(F.getOriginalPrice()));
                System.out.println(ticket);
                
                break;
            }
        }
    }
    public static void main(String[] args){
        
        Member m1 = new Member("Gajanan VIgneswaran", 19, 2);
        Member m2 = new Member("John Doe", 53, 7);
        NonMember nm1 = new NonMember("Real Person", 18);
        NonMember nm2 = new NonMember("Fake Person", 74);
        
        Manager m = new Manager();
        m.createFlights();
        
        m.displayAvailableFlights("t", "n");
        
        m.getFlight(1);
        
        m.bookSeat(1, m1);
        m.bookSeat(1, m2);
        m.bookSeat(1, nm1);
        m.bookSeat(1, nm2);
    }
    
}
