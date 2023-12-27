#### Overview
This program is an educational tool for the Engineering Electromagnetics course (EE3001) at NTU. It is designed to visualize the flow and calculations related to Uniform Plane Wave (UPW) reflection and refraction.

#### Key Components and Functions

1. **Header Files**
   ```cpp
   #include <iostream>
   #include <cstdlib>
   #include <math.h>
   ```

2. **Preprocessor Definitions**
   ```cpp
   #define WIDTH 50
   #define HEIGHT 25
   #define CENTER_i WIDTH/2
   #define CENTER_j HEIGHT/2
   #define OUTLINE '#'
   #define WAVE '0'
   #define VERTICAL_BOUNDARY '|'
   #define HORIZONTAL_BOUNDARY '-'
   #define CENTER_BONDARY '+'
   ```

3. **Function: degreeToRad**
   - Converts degrees to radians.
   ```cpp
   double degreeToRad(double degree){
       return degree/180 * 22/7;
   }
   ```

4. **Function: calculateRelativeVectorAngle**
   - Calculates the angle relative to the center, in radians.
   ```cpp
   double calculateRelativeVectorAngle(int i, int j){
       double x = CENTER_i-i;
       double y = CENTER_j-j;
       return abs(atan(y/x)); // return the reference angle 
   }
   ```

5. **Function: draw**
   - Core function for drawing the wave pattern.
   - Parameters: `AOI` (Angle of Incidence), `n1` (Refractive index of first medium), `n2` (Refractive index of second medium).
   ```cpp
   void draw(double AOI, double n1, double n2){
       // Code for drawing the pattern
       // Utilizes loops and conditionals to create the visual representation
   }
   ```

6. **Function: displayCalculation**
   - Displays the given parameters and calculated results (incomplete in the current version).
   ```cpp
   void displayCalculation(double AOI,double n1,double n2){
       // Display logic for calculated parameters
   }
   ```

7. **Main Function**
   - Interactive loop for user input.
   - Calls `draw` and `displayCalculation` functions.
   ```cpp
   int main(){
       // Loop for input and function calls
   }
   ```

#### Visualization Details
- Uses ASCII characters to depict waves and boundaries on a grid.
- Represents the incident, reflected, and refracted waves based on input parameters.

#### Limitations and Future Improvements
- Completing the `displayCalculation` function to show detailed calculations.
- Enhancing grid resolution for better visualization.

#### Usage
- Useful for visualizing wave interactions in electromagnetics.
- Interactive inputs for angle of incidence and refractive indices.
