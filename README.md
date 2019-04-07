# fdf
A height map wireframe renderer in C using [minilibx](https://github.com/qst0/ft_libgfx). (42 Silicon Valley)

<p float="left">
  <img src="https://github.com/ashih42/fdf/blob/master/Screenshots/perspective.png" width="280" />
  <img src="https://github.com/ashih42/fdf/blob/master/Screenshots/parallel.png" width="280" /> 
  <img src="https://github.com/ashih42/fdf/blob/master/Screenshots/spherical.png" width="285" />
</p>

## Prerequisites

You are on macOS with `gcc` and `make` installed.

## Compiling

```
make
```

## Running

```
./fdf map_file
```

## Controls

### Top-level Controls
* `1` Select perspective projection.
* `2` Select parallel projection.
* `3` Select spherical projection.
* `4` Use given colors (white by default).
* `5` Use height-based colors.
* `Escape` Terminate the renderer.

### Viewport Controls

* `Spacebar` Reset to default view.

#### View Direction
* `Numpad 0` Preset isometric view.
* `Numpad 4` Look toward +Z-axis.
* `Numpad 1` Look toward -Z-axis.
* `Numpad 5` Look toward +X-axis.
* `Numpad 2` Look toward -X-axis.
* `Numpad 6` Look toward +Y-axis.
* `Numpad 3` Look toward -Y-axis.

#### Scaling
* `+` Increase scaling in X, Y, Z-axes.
* `-` Decrease scaling in X, Y, Z-axes.
* `Q` Increase scaling in X-axis.
* `W` Decrease scaling in X-axis.
* `E` Increase scaling in Y-axis.
* `R` Decrease scaling in Y-axis.
* `T` Increase scaling in Z-axis.
* `Y` Decrease scaling in Z-axis.

#### Rotation
* `Drag LMB` Rotate in X, Y-axes.
* `A` Increase rotation around X-axis.
* `S` Decrease rotation around X-axis.
* `D` Increase rotation around Y-axis.
* `F` Decrease rotation around Y-axis.
* `G` Increase rotation around Z-axis.
* `H` Decrease rotation around Z-axis.

#### Translation
* `Z` Increase translation along X-axis.
* `X` Decrease translation along X-axis.
* `C` Increase translation along Y-axis.
* `V` Decrease translation along Y-axis.
* `B` Increase translation along Z-axis.
* `N` Decrease translation along Z-axis.
