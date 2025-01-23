<h1 align="center">so_long</h1>
<p align="center">
  <img src="https://img.shields.io/badge/grade-100%2F100-green?style=for-the-badge&logo=42&labelColor=gray"/>
</p>

<p align="center">
  <a href="https://github.com/pin3dev/42_Cursus/tree/main/so_long">
    <img src="https://img.shields.io/badge/Game_Development-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Pathfinding-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Logic_Puzzles-blue?style=for-the-badge"/>
    <img src="https://img.shields.io/badge/Pixel_Graphics-blue?style=for-the-badge"/>
  </a>
</p>

<p align="center">
  <img src="" width="600" height="375" />
</p>

<h3>
  <p align="center">
    <a href="#introduction">Introduction</a> •
    <a href="#structure">Structure</a> •
    <a href="#docs">Docs</a> •
    <a href="#cloning">Cloning</a> •
    <a href="#usage">Usage</a> •
    <a href="#norms">Norms</a> •
    <a href="#tutorial">Tutorial</a> •
    <a href="#contributors">Contributors</a>
  </p>
</h3>

## 🗣️ Introduction <a id="introduction"></a>

The **so_long** project is a 2D game development challenge in which the player navigates a small map collecting collectibles and reaching an exit. The game integrates basic pathfinding logic, pixel graphics, and interactive gameplay using the **MiniLibX** graphical library.

This project aims to teach foundational game mechanics, graphics rendering, and algorithmic logic in a constrained environment, aligning with the [42 School](https://42.fr/en/homepage/) guidelines.

## 🧬 Project Structure <a id="structure"></a>

The **so_long** project has the following core components:

- **Game Mechanics**: Player movement, collectible items, and an exit condition.
- **Map Parsing**: The game loads a map from a `.ber` file, validating its format and structure.
- **Graphics**: The game renders the map using MiniLibX, handling animations, sprites, and user inputs.
- **Error Handling**: Proper error messages for invalid maps or gameplay interruptions.
- **Pathfinding**: Ensures the player can always reach the exit.

The project is implemented with modular code for readability and maintainability.

## 🗃️ Documentation <a id="docs"></a>

For detailed documentation, including function breakdowns and implementation notes, visit the following link:  

<p align="center">
  <a href="https://github.com/pin3dev/42_so_long/wiki">
    <img src="https://img.shields.io/badge/so_long_Docs-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 🫥 Cloning the Repository <a id="cloning"></a>

To clone this repository and compile the project, use the following commands:

```bash
git clone https://github.com/pin3dev/42_so_long.git
cd 42_so_long/so_long
```

This will download the project to your local machine. Once inside the `42_so_long` directory, you can compile and run the game using the provided `Makefile`.

## 🕹️ Compilation and Usage <a id="usage"></a>

### Makefile

A `Makefile` is provided to simplify the compilation process. The Makefile includes the following rules:

- `all`: Compiles the project.
- `clean`: Removes object files.
- `fclean`: Removes object files and the executable.
- `re`: Recompiles the entire project from scratch.

To compile the project, run:
```bash
make
```
This will generate the `so_long` executable.

### Running the Game

To start the game, provide a valid `.ber` map file as an argument:
```bash
./so_long assets/maps/OK/m1.ber
```

The player can move using **arrow keys**, collect all collectibles, and reach the exit to win the game.

### Example Map File

A valid `.ber` file looks like this:
```
1111111
1P0C1E1
1000001
1111111
```
Legend:
- `1`: Wall
- `0`: Empty space
- `P`: Player
- `C`: Collectible
- `E`: Exit

## ⚠️ Norms and Guidelines Disclaimer <a id="norms"></a>

This project adheres strictly to the [**42 Norm**](https://github.com/pin3dev/42_Cursus/blob/main/norme.en.pdf) coding guidelines. These guidelines enforce specific coding styles and practices, shaping the implementation of the project accordingly.

## 🔬 Tutorial <a id="tutorial"></a>

A step-by-step tutorial on completing the **so_long** project is available here:

<p align="center">
  <a href="https://github.com/pin3dev">
    <img src="https://img.shields.io/badge/so_long_Tutorial-lightgreen?style=for-the-badge"/>
  </a>
</p>

## 👥 Contributors <a id="contributors"></a>

<a href="https://github.com/pin3dev">
  <img src="https://img.shields.io/badge/Ivany_Pinheiro-%40pin3dev-purple?style=for-the-badge"/>  
</a>
<br>
<a href="https://github.com/clima-fr">
  <img src="https://img.shields.io/badge/Clara_Franco-%40clima--fr-purple?style=for-the-badge"/>  
</a>

