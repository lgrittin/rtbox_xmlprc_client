rmdir dist
rmdir build
del app.spec
pyinstaller --noconsole src/app.py