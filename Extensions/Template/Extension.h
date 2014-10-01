
class Extension
{
public:

    LPRDATA rdPtr;
    LPRH    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 251;
    static const int Version = 1;

    static const int OEFLAGS = 0;
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
    ~Extension();


    /*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr)

        Unlike rdPtr, you can store real C++ objects with constructors
        and destructors, without having to call them manually or store
        a pointer.
    */

    // int MyVariable;

	class Node
	{
		public:
			Node * NextNode;
			Node * PrevNode;
			bool sentinel;

			void setData(int value)
			{
				int_data = value;
			}

			int getIntData()
			{
				return int_data;
			}

			Node(int value, bool state)
			{
				int_data = value;
				sentinel = state;
			}

			Node(int value)
			{
				int_data = value;
				sentinel = false;
			}

			~Node()
			{
			}

		private:
			int int_data;
	};

	class LinkedList
	{
		public:

			static int ListSize;
			int getInt(int index);
			
			void setInt(int index, int value)
			{
				Node * buffer = this->headNode->NextNode;

				for(int i = 0; i < index && buffer->NextNode != NULL; index++)
				{
					buffer = buffer->NextNode;
				}

				buffer->setData(value);
			}

			Node * headNode;
			Node * tailNode;

			LinkedList()
			{
				headNode = new Node(-1, true);
				tailNode = new Node(-1, true);

				headNode->PrevNode = NULL;
				tailNode->NextNode = NULL;

				headNode->NextNode = tailNode;
				tailNode->PrevNode = headNode;

			}
			~LinkedList()
			{
				for(int i = 0; i < Extension::LinkedList::ListSize; i++)
				{
					removeFront();
				}

				Extension::LinkedList::ListSize = 0;
				delete headNode;
				delete tailNode;

			}

			void addEnd(int value)
			{
				Node * buffer = new Node(value);

				buffer->PrevNode = tailNode->PrevNode;
				buffer->NextNode = tailNode;
				
				tailNode->PrevNode->NextNode = buffer;
				tailNode->PrevNode = buffer;
				
				++Extension::LinkedList::ListSize;
			}
			void addFront(int value)
			{
				Node * buffer = new Node(value);

				buffer->NextNode = headNode->NextNode;
				buffer->PrevNode = headNode;

				headNode->NextNode->PrevNode = buffer;
				headNode->NextNode = buffer;

				++Extension::LinkedList::ListSize;
			}

			void removeFront()
			{
				if(headNode->NextNode->sentinel == false)
				{
					
					Node * buffer = headNode->NextNode;

					headNode->NextNode = buffer->NextNode;
					buffer->NextNode->PrevNode = buffer->PrevNode;

					delete buffer;
					Extension::LinkedList::ListSize--;
				}
			}
			void removeEnd()
			{
				if(tailNode->PrevNode->sentinel == false)
				{
					
					Node * buffer = tailNode->PrevNode;

					tailNode->PrevNode = buffer->PrevNode;
					buffer->PrevNode->NextNode = buffer->NextNode;

					delete buffer;
					--Extension::LinkedList::ListSize;
				}
			}

			Node * findNode(int index)
			{
				Node * buffer;
				
				buffer = headNode->NextNode;
				for(int i = 0; i < index; i++)
				{
					buffer = buffer->NextNode;
				}
				
				return buffer;
			}


	} FusionLList;

	
    /*  Add your actions, conditions and expressions as real class member
        functions here. The arguments (and return type for expressions) must
        match EXACTLY what you defined in the JSON.

        Remember to link the actions, conditions and expressions to their
        numeric IDs in the class constructor (Extension.cpp)
    */

    /// Actions

		void addFrontNode(int value);
		void addEndNode(int value);
		void addAnyNode(int index, int value);

		void removeFrontNode();
		void removeEndNode();
		void removeAnyNode(int index);

		void erase(int index, int amount);
		void swap(int indexA, int indexB);
		void reverse();
		void reverseSection(int indexA, int indexB); 

    /// Conditions

		bool emptyList();
		bool NodeInsertion();
		bool NodeRemoval();
		bool ListClear();


    /// Expressions

		int getStartData();        
		int getEndData();
		int getData(int index);
		int ListSize();


    /* These are called if there's no function linked to an ID */

    void Action(int ID, LPRDATA rdPtr, long param1, long param2);
    long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
    long Expression(int ID, LPRDATA rdPtr, long param);


	

    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};