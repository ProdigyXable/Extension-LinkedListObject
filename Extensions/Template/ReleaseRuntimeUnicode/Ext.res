        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Linked List Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright � 2014 Xable Enterprises",
        "Comment": "This extension allows the easy implementation of linked lists and linked lists structures, such as stacks and queues, within MMFusion",
        "URL": "",
        "Help": "",
        "Identifier": "PXLL"
    },
    "ActionMenu": 
	[
		["Node Insertion",
		
			[4,"Add Node to Start of List"],
			[0,"Add Node to End of List"],
			"Separator",
			[5,"Add Node"],
		],

		["Node Removal",
			[1,"Remove Front Node"],
			[2,"Remove End Node"],
			"Separator",
			[3,"Remove Node"],
			"Separator",
			[6, "Erase Nodes"],
		],

		["Node Manipulation",
			[7,"Swap Nodes"],
			[8,"Reverse List"],
			[9,"Reverse List Subsection"],

		],
    ],

    "ConditionMenu": 
	[
		[0, "Is list empty?"],
		"Separator",
		[1,"Node just added?"],
		[2,"Node just removed?"],
		[3,"List just leared?"],
		[4,"Index Bound Error"],
		"Separator",
	],

    "ExpressionMenu": [
	["Node Data",
        [2,"Get Data from Start Node"],
		[0,"Get Data from End Node"],
		"Separator",
		[3,"Get Data from Node"],
	],
		"Separator",
		[1, "List Size"],
		"Separator",
    ],
    "Actions": 
	[
        {"Title": "Add Node to end with data %0",
            "Parameters": 
			[
				["Integer","Initial Data"]
            ]
        },
		{"Title": "Remove Front Node",
        },
		{"Title": "Remove End Node",
        },
		{"Title": "Remove Node with index %0",
            "Parameters": 
			[
				["Integer","Node Index"]
            ]
        },
		{"Title": "Add Node to start with data %0",
            "Parameters": 
			[
				["Integer","Initial Data"]
            ]
        },
		{"Title": "Insert Node to index %0 with data %1",
            "Parameters": 
			[
				["Integer","Node Index"],
				["Integer","Initial Data"]
            ]
        },
		{"Title": "Erase %1 node(s) starting with node %0",
            "Parameters": 
			[
				["Integer","Node Index"],
				["Integer","Erase Amount"]
            ]
        },
		{"Title": "Swap node %0 with node %1",
            "Parameters": 
			[
				["Integer","Node Index A"],
				["Integer","Node Index B"]
            ]
        },
		{"Title": "Reverse List",
        },
		{"Title": "Reverse List from index %0 to %1",
            "Parameters": 
			[
				["Integer","Node Index A"],
				["Integer","Node Index B"]
            ]
        },
    ],
    "Conditions": 
	[
		{
			"Title": "%o : Is list empty?",
            "Parameters":
			[
            ],
            "Triggered": false
        },
		{
			"Title": "%o : Node just added",
            "Parameters":
			[
            ],
            "Triggered": true
        },
		{
			"Title": "%o : Node just removed",
            "Parameters":
			[
            ],
            "Triggered": true
        },
		{
			"Title": "%o : List just cleared",
            "Parameters":
			[
            ],
            "Triggered": true
		},        
		{
			"Title": "%o : Index boundary error",
            "Parameters":
			[
            ],
            "Triggered": true
        },
    ],
    "Expressions": 
	[
        {
			"Title": "GetEndData(",
			 "Returns": "Integer",
        },
		{
			"Title": "ListSize(",
			 "Returns": "Integer",
        },
		{
			"Title": "GetStartData(",
			 "Returns": "Integer",
        },
		{
			"Title": "GetData(",
			"Returns": "Integer",
			"Parameters": 
			[
				["Integer","Node Index"],
            ]
			 
        },
    ]
} &       �� ��     0	           M F 2                               