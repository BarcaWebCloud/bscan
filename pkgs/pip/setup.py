import pathlib
from setuptools import setup
HERE = pathlib.Path(__file__).parent
README = (HERE / "README.md").read_text()
setup(
  name="bwc-bscan",
  version="0.1.0",
  description="A library For Getting Information on Hardware, Software and Atmospheres for Python. Developers can troubleshoot Issues Using the Library in Mobile and Web Apps.",
  long_description=README,
  long_description_content_type="text/markdown",
  author='Aníbal Barca, ',
  author_email='anibalbs@barca.com, ',
  license="MIT",
  packages=["bwc-bscan"],
  zip_safe=False
)