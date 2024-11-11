# Dynamic_Graphics_Design_Patterns
Decorator, Observer, and Visitor Pattern Graphics Project


*Project Overview :*

This project is a C++ application that models a graphical system with shapes that can be decorated, observed, and analyzed. It utilizes the Decorator, Observer, and Visitor design patterns to allow dynamic styling, state observation, and calculations (e.g., perimeter and surface area) on shapes. By leveraging these design patterns, the project showcases extensibility and modularity, making it easier to manage complex graphical operations and computations.

*Project Structure :*

  - Decorator Pattern:

    Allows dynamic addition of properties such as colors and contours to shapes.

    Files:
      - figure.h / figure.cpp: Base class for shapes.
      - decorator.h: Abstract decorator for extending Figure.
      - decorator_contour.h: Adds contour styling to shapes.
      - decorator_fillcolor.h: Adds fill color capability to shapes.
        
  - Observer Pattern:
    
    Enables real-time updates on shape state changes.
    
    Files:
    
      - observer.h: Defines the Observer interface.
      - observer_console.h: Outputs changes in shape states to the console.

  - Visitor Pattern:

    Supports additional operations on shapes, like calculating perimeter and surface area, without modifying the shapes themselves.
    
    Files:
    
      - visitor.h: Defines the Visitor interface.
      - visitor_perimeter.h: Calculates the perimeter of shapes.
      - visitor_surface.h: Calculates the surface area of shapes.
      - Additional Components
        
  - Graphics Management:

    Files :
    
      - concrete_figures.h: Defines specific shapes (e.g., circles, rectangles).
      - group.h / group.cpp: Manages groups of shapes, allowing collective operations on multiple shapes.
