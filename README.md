# HTTP-Server-C

## **Installation**

1. Clone the repository (if applicable):
   ```bash
   git clone https://github.com/Himesh-Kundal/HTTP-Server-C
   cd <HTTP-Server-C>
   ```

2. Compile the program:
   ```bash
   gcc main.c Server.c -o server
   ```

---

## **Usage**

### **Run the Server**

Start the server by specifying the port number as an argument:

```bash
./server <port>
```

For example:

```bash
./server 8080
```

The server will then start and listen for HTTP requests on the specified port.

---

### **Test the Server**

Once the server is running, you can test it using:

- **Curl**: Use the `curl` command in your terminal:
  ```bash
  curl http://localhost:8080
  ```

---

## **Troubleshooting**

1. **Port Already in Use**:
   If you encounter an error such as:
   ```
   bind: Address already in use
   ```
   Make sure no other service is using the specified port.

   To check:
   ```bash
   netstat -tuln | grep <port>
   ```

   To kill the process using the port:
   ```bash
   kill -9 <pid>
   ```

2. **Firewall Issues**:
   Ensure the specified port is open in your firewall settings.

---