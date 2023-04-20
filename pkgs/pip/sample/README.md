### BScan package to Python using pip.

<br>

See [documentation](http://docs.barca/bwc/modules/bscan#bscan-py)

<br>
<br>

## Installation

Install the package with pip:

### via PyPI:

<br>

```
pip install bwc-bscan
```

<br>

### or via GitHub:

<br>

```
pip install git+https://github.com/BarcaWebCloud/bscan-py.git
```

<br>
<br>

Create a *Python* file to start using the `bscan` *package* in your project. In the example below, the file named `main.py` was specified to run the **bscan module**. Add the following content in the main file.

<br>

`main.py`

```py
import importlib

bwc_bscan = importlib.import_module("bwc-bscan")
init = bwc_bscan.bscan

init()

```
<br>
<br>

[bwc-bscan](https://pypi.org/project/bwc-bscan/)