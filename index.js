class Transposition {
    constructor() {
        let inputValue = document.querySelector('input#word').value;

        if (Module.validInput(inputValue)) {
            this.userInput = inputValue;
        } else {
            throw new Error('No invalid characters!');
        }
    }

    transpot = () => {
        const userString = this.userInput;
        let newString = "";

        for (let i = 0; i < userString.length; ++i) {
            // userString.charCodeAt returns a character code
            // Module.transport() returns an ASCII value in decimal
            // String.fromCharCode() translates it back to the character we wanted and appends it
            // to newString
            newString += String.fromCharCode(Module.transpot(userString.charCodeAt(i)));
        }

        return newString;
    };

    undoTranspot = (transpotString) => {
        let oldString = "";

        for (let i = 0; i < transpotString.length; ++i) {
            // userString.charCodeAt returns a character code
            // Module.transport() returns an ASCII value in decimal
            // String.fromCharCode() translates it back to the character we wanted and appends it
            // to newString
            oldString += String.fromCharCode(Module.undoTranspot(transpotString.charCodeAt(i)));
        }

        return oldString;
    };
}

const onSubmit = () => {
    document.querySelector('.form').addEventListener('submit', (event) => {
        // Submit event causes page to refresh and preventDefault prevents the refresh.
        event.preventDefault();

        const inputObject = new Transposition();

        const encryptedWord = inputObject.transpot();
        const decryptedWord = inputObject.undoTranspot(encryptedWord);

        document.querySelector('#encrypted').textContent = encryptedWord;
        document.querySelector('#decrypted').textContent = decryptedWord;
    });
};

const main = () => {
    onSubmit();
};

main();