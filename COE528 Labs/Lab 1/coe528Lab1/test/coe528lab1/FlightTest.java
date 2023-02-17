/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coe528lab1;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Gajanan Vigneswaran
 */
public class FlightTest {
    
    public FlightTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of setFlightNumber method, of class Flight.
     */
    @Test
    public void testConstructor() {
        System.out.println("Constructor");
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100.0);
        assertEquals(1, instance.getFlightNumber());
        assertEquals("toronto", instance.getorigin());
        assertEquals("ottawa", instance.getDestination());
        assertEquals("21/1/23 8:12pm", instance.getDepartureTime());
        assertEquals(10, instance.getCapacity());
        assertEquals(100.0, instance.getOriginalPrice(),0.009);
    }
    @Test (expected = IllegalArgumentException.class)
    public void testInvalidConstructor() {
        Flight instance = new Flight(1, "toronto", "toronto", "21/1/23 8:12pm", 10, 100);
    }
    
    @Test
    public void testSetFlightNumber() {
        System.out.println("setFlightNumber");
        int flightNumber = 2;
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        instance.setFlightNumber(flightNumber);
        
    }

    /**
     * Test of getFlightNumber method, of class Flight.
     */
    @Test
    public void testGetFlightNumber() {
        System.out.println("getFlightNumber");
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        int expResult = 1;
        int result = instance.getFlightNumber();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of setOrigin method, of class Flight.
     */
    @Test
    public void testSetOrigin() {
        System.out.println("setOrigin");
        String origin = "place";
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        instance.setOrigin(origin);
        
    }

    /**
     * Test of getorigin method, of class Flight.
     */
    @Test
    public void testGetorigin() {
        System.out.println("getorigin");
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        String expResult = "toronto";
        String result = instance.getorigin();
        assertEquals(expResult, result);
       
    }

    /**
     * Test of setDestination method, of class Flight.
     */
    @Test
    public void testSetDestination() {
        System.out.println("setDestination");
        String destination = "york";
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        instance.setDestination(destination);
        
    }

    /**
     * Test of getDestination method, of class Flight.
     */
    @Test
    public void testGetDestination() {
        System.out.println("getDestination");
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        String expResult = "ottawa";
        String result = instance.getDestination();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of setDepartureTime method, of class Flight.
     */
    @Test
    public void testSetDepartureTime() {
        System.out.println("setDepartureTime");
        String departureTime = "1/71/22 9:12pm";
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        instance.setDepartureTime(departureTime);
        
    }

    /**
     * Test of getDepartureTime method, of class Flight.
     */
    @Test
    public void testGetDepartureTime() {
        System.out.println("getDepartureTime");
        Flight instance = new Flight(1, "toronto", "ottawa", "21/1/23 8:12pm", 10, 100);
        String expResult = "21/1/23 8:12pm";
        String result = instance.getDepartureTime();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of setCapacity method, of class Flight.
     */
    @Test
    public void testSetCapacity() {
        System.out.println("setCapacity");
        int capacity = 3;
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100);
        instance.setCapacity(capacity);
        
    }

    /**
     * Test of getCapacity method, of class Flight.
     */
    @Test
    public void testGetCapacity() {
        System.out.println("getCapacity");
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100);
        int expResult = 10;
        int result = instance.getCapacity();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of setOriginalPrice method, of class Flight.
     */
    @Test
    public void testSetOriginalPrice() {
        System.out.println("setOriginalPrice");
        double originalPrice = 10.0;
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100);
        instance.setOriginalPrice(originalPrice);
        
    }

    /**
     * Test of getOriginalPrice method, of class Flight.
     */
    @Test
    public void testGetOriginalPrice() {
        System.out.println("getOriginalPrice");
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100.0);
        double expResult = 100.0;
        double result = instance.getOriginalPrice();
        assertEquals(expResult, result, 0.0);
        
    }

    /**
     * Test of setNumberOfSeatsLeft method, of class Flight.
     */
    @Test
    public void testSetNumberOfSeatsLeft() {
        System.out.println("setNumberOfSeatsLeft");
        int numberOfSeatsLeft = 4;
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100.0);
        instance.setNumberOfSeatsLeft(numberOfSeatsLeft);
        
    }

    /**
     * Test of getNumberOfSeatsLeft method, of class Flight.
     */
    @Test
    public void testGetNumberOfSeatsLeft() {
        System.out.println("getNumberOfSeatsLeft");
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 0, 100.0);
        int expResult = 0;
        int result = instance.getNumberOfSeatsLeft();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of bookASeat method, of class Flight.
     */
    @Test
    public void testBookASeat() {
        System.out.println("bookASeat");
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 0, 100.0);
        boolean expResult = false;
        boolean result = instance.bookASeat();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of toString method, of class Flight.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Flight instance = new Flight(1, "toronto", "ottawa", "21,1,23 8:12pm", 10, 100.0);
        String expResult = "Flight 1, toronto to ottawa, 21,1,23 8:12pm, original price: 100.0$";
        String result = instance.toString();
        assertEquals(expResult, result);
        
    }
    
}
