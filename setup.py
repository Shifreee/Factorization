from distutils.core import setup, Extension

module1 = Extension("fact",
                    sources=['factorization_python.c'])

setup(
    name="fact",
    version="1.0",
    description="This is a fast factorization package",
    ext_modules=[module1],
)
