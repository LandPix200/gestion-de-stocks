import os
from pathlib import Path


if __name__ == "__main__":
    
    for f in Path(os.curdir).iterdir():
        if str(f).__contains__(".d") and not str(f).__contains__(".db"):
            os.remove(f)