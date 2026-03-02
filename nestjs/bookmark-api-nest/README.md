# Bookmark API Documentation

This documentation provides a detailed overview of the Bookmark API endpoints, including expected inputs, successful responses, and error handling.

## 🚀 Getting Started

A Postman collection is available in the root directory for immediate testing:
**File:** `Bookmarks.postman_collection.json`

---

## 🛠 Global Configuration
- **Base URL**: `http://localhost:1234`
- **Content-Type**: `application/json`

---

## 📁 API Endpoints

### 1. API Information
Returns metadata about the current API version and available features.

* **URL**: `/`
* **Method**: `GET`
* **Success Response (200 OK)**:
    ```json
    {
      "message": "info about this api :__:",
      "requists": ["get all bookmarks", "get bookmark by id", ...],
      "version": "1.0.0"
    }
    ```

---

### 2. Get All Bookmarks (Paginated)
Fetches a list of bookmarks with built-in pagination.

* **URL**: `/bookmarks`
* **Method**: `GET`
* **Query Parameters**:
    | Parameter | Type | Default | Description |
    | :--- | :--- | :--- | :--- |
    | `limit` | number | 10 | Number of items per page |
    | `page` | number | 1 | Current page number |

* **Success Response (200 OK)**:
    ```json
    {
      "message": "get all bookmarks",
      "data": [
        {
          "_id": "65f1...",
          "url": "[https://google.com](https://google.com)",
          "title": "Google",
          "tags": ["search"],
          "createdAt": "2024-03-12T..."
        }
      ],
      "pagination": {
        "limit": 10,
        "currentPage": 1,
        "pages": 5,
        "total": 48
      }
    }
    ```

---

### 3. Create a Bookmark
Adds a new bookmark to the database.

* **URL**: `/bookmarks`
* **Method**: `POST`
* **Request Body (Required)**:
    | Field | Type | Required | Description |
    | :--- | :--- | :--- | :--- |
    | `url` | string | Yes | The full URL of the bookmark |
    | `title` | string | Yes | Display title |
    | `description`| string | No | Short summary |
    | `tags` | string[]| No | Array of category strings |

* **Success Response (201 Created)**: Returns the created Bookmark object including `_id`.
* **Error Response (400 Bad Request)**: 
    - Occurs if `url` or `title` is missing.
    - Output: `{ "message": ["url should not be empty"], "error": "Bad Request", "statusCode": 400 }`

---

### 4. Get Bookmark by ID
Retrieves a specific bookmark using its unique MongoDB ID.

* **URL**: `/bookmarks/:id`
* **Method**: `GET`
* **Success Response (200 OK)**: Returns the single Bookmark object.
* **Error Response (404 Not Found / Logical Error)**:
    ```json
    {
      "message": "there is no bookmark found with this id",
      "success": false
    }
    ```

---

### 5. Update Bookmark
Modifies an existing bookmark. All fields in the body are optional.

* **URL**: `/bookmarks/:id`
* **Method**: `PUT`
* **Request Body**:
    ```json
    {
      "title": "Updated Title",
      "tags": ["new-tag"]
    }
    ```
* **Success Response (200 OK)**: Returns the updated Bookmark object.
* **Error Response (Success: false)**:
    ```json
    {
      "message": "bookmark not found",
      "success": false
    }
    ```

---

### 6. Delete Bookmark
Removes a bookmark permanently.

* **URL**: `/bookmarks/:id`
* **Method**: `DELETE`
* **Success Response (200 OK)**:
    ```json
    {
      "message": "bookmark deleted successfully",
      "success": true
    }
    ```
* **Error Response (404/Error)**:
    ```json
    {
      "message": "no bookmark found with this id",
      "success": false
    }
    ```

---

## 📊 Data Models



### Bookmark Schema
| Property | Type | Description |
| :--- | :--- | :--- |
| `url` | String | Required |
| `title` | String | Required |
| `description`| String | Optional |
| `tags` | String[] | Default: [] |
| `timestamps` | Date | Automatically generated `createdAt` and `updatedAt` |