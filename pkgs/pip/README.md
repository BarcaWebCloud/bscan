### Pip [bwc-bscan 0.1.0](https://pypi.org/project/bwc-bscan/0.1.0/) 

This project defines itself as a python module for scanning computational devices. Proposing a pleasant experience for web and mobile developers.


#### To Developers

<br>

1. Install the **wheel** module in your python environment

`pip install wheel`

<br>

2. Install **twine** which will be used to upload the tarball

`pip install twine`

<br>

3. Now compile the library setup of bscan module

`python .\setup.py sdist bdist_wheel`

...

<br>

4. Publish or update package in Pip Manager

```
python3 -m twine upload dist/*
```